for i in $(seq 1 1000); do
  mkdir "dir$i"
  for j in $(seq 1 10000); do
    : > "dir$i/file_${j}" &
  done
done
