#!/bin/zsh

mkdir -p tmp
mkdir -p traces

ok=()
not_ok=()

for i in *.py; do
    # skip main.c file
    if [[ $i == "solution.py" ]]; then
        continue
    fi

    output=${i%.*}
    trace="traces/${output}_trace.txt"
    expected_file="./tmp/${output}_expected.txt"
    output_file="./tmp/${output}_output.txt"
    echo "Processing: $output"

    echo "#1(no args) " | tee -a $expected_file $output_file
    ./solution.py $output &>> $expected_file
    ./$i &>> $output_file

    echo "#2(empty) " | tee -a $expected_file $output_file
    ./solution.py $output "" &>> $expected_file
    ./$i "" &>> $output_file

    echo "#3(two args) " | tee -a $expected_file $output_file
    ./solution.py $output "firstArg" "secondArg" &>> $expected_file
    ./$i "firstArg" "secondArg" &>> $output_file

    echo "#4(invalid char) " | tee -a $expected_file $output_file
    ./solution.py $output "sos daily##@" &>> $expected_file
    ./$i "sos daily##@" &>> $output_file

    echo "#5(soS) " | tee -a $expected_file $output_file
    ./solution.py $output "soS" | cat -e >> $expected_file
    ./$i "soS" | cat -e >> $output_file

    echo "#6(daily) " | tee -a $expected_file $output_file
    ./solution.py $output "daily" | cat -e >> $expected_file
    ./$i "daily" | cat -e >> $output_file

    echo "#7(proGrammer) " | tee -a $expected_file $output_file
    ./solution.py $output "proGRammer" | cat -e >> $expected_file
    ./$i "proGRammer" | cat -e >> $output_file

    echo "#8(sos daily) " | tee -a $expected_file $output_file
    ./solution.py $output "sos daily" | cat -e >> $expected_file
    ./$i "sos daily" | cat -e >> $output_file

    echo "#9(AwfXViwIATRPpEJFxCjn) " | tee -a $expected_file $output_file
    ./solution.py $output "AwfXViwIATRPpEJFxCjn" >> $expected_file
    ./$i "AwfXViwIATRPpEJFxCjn" >> $output_file

    echo "#10(CePwvYCExojnlxIYMmnG) " | tee -a $expected_file $output_file
    ./solution.py $output "CePwvYCExojnlxIYMmnG" >> $expected_file
    ./$i "CePwvYCExojnlxIYMmnG" >> $output_file

    echo "#11(NqidxKHSmisgTYMCnRnF) " | tee -a $expected_file $output_file
    ./solution.py $output "NqidxKHSmisgTYMCnRnF" >> $expected_file
    ./$i "NqidxKHSmisgTYMCnRnF" >> $output_file

    echo "#12(AZZLztCgwZZvEicNVZnf) " | tee -a $expected_file $output_file
    ./solution.py $output "AZZLztCgwZZvEicNVZnf" >> $expected_file
    ./$i "AZZLztCgwZZvEicNVZnf" >> $output_file

    echo "#13(tab    tab) " | tee -a $expected_file $output_file
    echo "usage: ./${output}.py <a-zA-Z string>" >> $expected_file
    ./$i "tab\ttab" &>> $output_file

    diff $expected_file $output_file >> $trace
    if [[ $? -eq 0 ]]; then 
        echo "Diff: OK" >> $trace
        ok+=($i)
    else
        echo "Diff: KO" >> $trace
        not_ok+=($i)
    fi

done

echo "OK: $ok"
echo "NOT_OK: $not_ok"