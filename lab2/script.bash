#!/bin/bash
echo "В какой директории вы хотите удалить пустые файлы? Y -  выбрать текущую, N - ввести вручную"
choice=""
read choice
if [ $choice = "Y" ] || [$choice = "y"]
then
mydir=$(pwd)
emptyFiles=$(find $mydir -empty)
        if rm $emptyFiles
        then
        echo "Пустые файлы были удалены, скрипт завершен"
        else
        echo "Пустые файлы не найдены"
        fi
elif [ $choice = "N" ] || [ $choice = "n"]
then
mydir=""
read mydir
emptyFiles=$(find $mydir -empty)
        if rm $emptyFiles
        then
        echo "Пустые файлы были удалены, скрипт завершен"
        else
        echo "Пустые файлы не найдены"
        fi
else
echo "Вы ввели неправильные данные, перезапустите скрипт"
fi
