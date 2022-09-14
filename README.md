# ipaddr
Simple little program to display your IP address in a meaningful uncluttered format.

## Building
```
$ gcc ipaddr.c -o ipaddr
$ sudo cp ./ipaddr /usr/local/bin
```

## Execute

```
$ ipaddr

------------------------------------------------------------
IPv4 ADDRESSES:
------------------------------------------------------------
lo         127.0.0.1
enp4s0f3u2 192.168.2.153
wlp3s0     192.168.1.102

------------------------------------------------------------
IPv6 ADDRESSES:
------------------------------------------------------------
lo         ::1
enp4s0f3u2 fa80::8262:87bf:ab3:e437%enp4s0f3u2
wlp3s0     fd80::4e6d:ade7:fda2:e813%wlp3s0
