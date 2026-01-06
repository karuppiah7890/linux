for i in {1..2476300}; do
  echo -n > "kp${i}.txt" &
done
