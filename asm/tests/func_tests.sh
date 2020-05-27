#!/usr/bin/env bash

x=$(find ./champions/src/ -name "*.s")

granted=0
failed=0

for i in $x; do
  ../asm "$x"
  if [ $? -ne 0 ]; then
    echo "Compilation of $i failed"
    let failed++
  else
    ex=${i/src/.}
    test=${i/src/'..'}
    c=$(diff ${test/.s/.cor} ${ex/.s/.cor})
    echo "$c"
    if [ -z $c ]; then
      echo "Compilation of $i granted"
      let granted++
    else
      echo "Compilation of $i failed"
      let failed++
    fi
  fi
done

echo "Tests completed:"
echo "$granted granted"
echo "$failed failed"