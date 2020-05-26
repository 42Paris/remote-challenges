#!/bin/zsh

mkdir -p tmp
mkdir -p ../traces

ok=()
not_ok=()

for i in ../*.py; do
    for j in *_in.txt; do
        #test number
        testnum=${j:s/_in.txt/}

        # login
        login=${i:s/.py/}
        login=${login:s/..\//}

        echo ${login}:
        cat $j | $i >> tmp/${login}.txt
    done
    diff expected.txt tmp/${login}.txt > ../traces/${login}.txt
    if [[ $? -eq 0 ]]; then
        echo "Diff: OK" >> ../traces/${login}.txt
        ok+=($login)
    else
        echo "Diff: KO" >> ../traces/${login}.txt
        not_ok+=($login)
    fi
done

print OK: $ok
print NOT_OK: $not_ok
