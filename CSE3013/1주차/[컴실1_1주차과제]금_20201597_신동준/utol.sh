echo "working directory:"
read dirname
if [ -n "$dirname" ]
then
        cd $dirname
        if [ $? != 0 ]
        then
                msg="Error: cannot access directory"
                echo $msg
                exit 0
        fi
fi
for dir in *
do
        newname=`echo $dir | tr "[a-zA-Z]" "[A-Za-z]"`
        mv $dir $newname
done
