#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd $DIR

ERROR_1=0
ERROR_2=0
ERROR_3=0

function check()
{
    ERROR=0
    for f in $(find tests/$1 -type f -name "*.lat")
    do
        echo "$f:"
        ./latc_x86 $f >> /dev/null
        if [[ $? -ne $2 ]] ; then
            echo -e "\e[92mOK!\e[0m"

            if [[ $2 -eq 1 ]] ; then
                if [[ -f "${f%.*}.input" ]] ; then
                    cat "${f%.*}.input" | ./${f%.*} > ${f%.*}.output.temp
                else
                    ./${f%.*} > ${f%.*}.output.temp
                fi

                if [[ -f "${f%.*}.output" ]] ; then
                    diff -q --ignore-all-space "${f%.*}.output" "${f%.*}.output.temp" > /dev/null

                    if [[ $? -eq 0 ]] ; then
                        echo -e "\e[92mOK!\e[0m"
                    else
                        ERROR=1
                        echo -e "\033[31mERROR OUTPUT!\e[0m"
                    fi
                else
                    echo -e "\e[92mOK!\e[0m"
                fi

	            rm "${f%.*}"
                rm "${f%.*}.output.temp"
            fi
        else
            ERROR=1
            echo -e "\033[31mERROR COMPILATION!\e[0m"
        fi
    done

    return $ERROR
}

function print()
{
    if [[ $1 -eq 0 ]] ; then
        echo -e "\e[92mOK!\e[0m"
    else
        echo -e "\033[31mFAILED!\e[0m"
    fi
}

if [[ $# -eq 0 ]] ; then
    echo "BAD TESTS CHECK:"
    check "bad" 0
    ERROR_1=$?

    echo -e "\n\nCORE TESTS CHECK:"
    check "good" 1
    ERROR_2=$?

    echo -e "\n\nEXTENSIONS TESTS CHECK:"
    check "extensions" 1
    ERROR_3=$?

    echo -e "\nBad: "
    print $ERROR_1

    echo "Core: "
    print $ERROR_2

    echo "Extensions: "
    print $ERROR_3
else
    echo $1" check:"
    check $1 $2
    ERROR=$?
    echo -e "\nResult:"
    print $ERROR
fi
