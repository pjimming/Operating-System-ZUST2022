#!/bin/bash
function square {
    local sq     # sq is local to the function
    let "sq=$1 * $1"
    echo "Number to be squared is $1."
    echo "The result is $sq "
}
echo "Give me a number to square. "
read number
value_returned=$(square $number)  # Command substitution,调用函数
echo   "$value_returned"         #输出函数执行结果

