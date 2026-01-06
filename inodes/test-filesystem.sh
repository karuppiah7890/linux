dd if=/dev/zero of=myfs.img bs=1K count=1024

ls -lh myfs.img

sudo mkdir /mnt/myloop

ls /mnt

ls /mnt/myloop

sudo mount myfs.img /mnt/myloop

ls /mnt

ls /mnt/myloop

mount | grep loop

df -i

df -i | grep /mnt/myloop

sudo chown -R $(whoami):$(whoami) /mnt/myloop/
