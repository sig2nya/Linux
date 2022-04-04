```js
arr_test_string=(1 2 3 4 5)
arr_test_string+=(6)
arr_test_string+=(7 8)

for i in ${arr_test_string[@]}; do
        echo $i
done

arr_test=(1 2 3)
remove_element=(3)

arr_test=("${arr_test[@]/$remove_element}")

for i in ${arr_test[@]}; do
        echo $i
done

arr_test=("abc" "def" "ghi")
remove_element=("ghi")

arr_test=("${arr_test[@]/$remove_element}")

for i in ${arr_test[@]}; do
        echo $i
done

arr_test=("abc" "def" "defghi")
remove_element=("def")

arr_test=("${arr_test[@]/$remove_element}")

for i in ${arr_test[@]}; do
        echo $i
done

arr_test=("abc" "def" "defghi")
remove_element=("def")

echo ${!arr_test[@]}

for i in ${!arr_test[@]}; do
        if [ ${arr_test[i]}=${remove_element} ]; then
                unset arr_test[i]
        fi
done

for i in ${arr_test[@]}; do
        echo $i
done
```
