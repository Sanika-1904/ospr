#/bin/bash
create()
{
echo "Enter file name"
read filename
if [ -f $filename ]
then
echo "file exixts"
else
touch $filename
fi
echo "Address Book is created"
}
insert()
{
echo "Enter number of records you want to insert"
read n
echo "Insert data like"
echo "ROLL_NO NAME MOB_NO EMAIL_ID CITY"
for (( i=0;i<=n;i++ ))
do
read a
echo $a>>$filename
done
echo "data is inserted"
}
display()
{
echo "STUDENT address book is as follows"
echo "ROLL_NO NAME MOB_NO EMAIL_ID CITY"
cat $filename
}
search()
{
echo "Enter roll no to be searched:"
read s
echo "ROLL_NO NAME EMAIL_ID CITY"
if [ $(grep -wc "$s" $filename) -eq 1 ]
then
echo "Record found"
echo "ROLL_NO NAME MOB_NO EMAIL_ID CITY"
grep -w "$s" $filename
else
echo "record not found"
fi
}

modify()
{
echo "Enter roll no to be modified"
read s
echo "Enter new record"
echo "ROLL_NO NAME MOB_NO EMAIL_ID CITY"
read r
sed -i "/$s/c $r" $filename
echo "record is modified"
}
delete()
{
echo "Enter roll no to be deleted"
read s
grep -v "$s" $filename > filename2 ; mv filename2 $filename
echo "record deleted"
}
#switch-case
until ["$ch"="6"]; do
echo "ADDRESS BOOK OF STUDENT"
echo "1.Create Address Book"
echo "2.Insert Record"
echo "3.Display Record"
echo "4.Search Record"
echo "5.Modify Record"
echo "6.Delte Record"
echo "7.EXIT"
echo "Enter your choice"
read ch
case $ch in
1)create;;
2)insert;;
3)display;;
4)search;;
5)modify;;
6)delete;;
7);;
esac
done
