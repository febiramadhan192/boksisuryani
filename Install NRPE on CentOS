
#!/bin/bash

#update
echo "INSTALL REPO EPEL DAN UPDATE"
yum install epel-release
yum update

#install paket yang dibutuhkan
echo "INSTALL DEPEDENCIES YANG DIBUTUHKAN"
yum install -y gcc glibc glibc-common gd gd-devel make net-snmp openssl-devel

#buat user nagios
echo "MEMBUAT USER ATAS NAMA NAGIOS DAN MEMASUKAN PASSWORDNYA"
useradd nagios
passwd nagios

#download dan install nagios plugin
echo "DOWNLOAD DAN INSTALL NAGIOS PLUGIN"
wget https://www.nagios-plugins.org/download/nagios-plugins-1.5.tar.gz
tar xzvf nagios-plugins-1.5.tar.gz
cd nagios-plugins-1.5
./configure
make
make install
chown nagios.nagios /usr/local/nagios
chown -R nagios.nagios /usr/local/nagios/libexec
cd

#install xinetd
echo "INSTALL PAKET XINETD"
yum -y install xinetd

#download dan install nrpe
echo "DOWNLOAD DAN INSTALL NRPE"
wget http://sourceforge.net/projects/nagios/files/nrpe-2.x/nrpe-2.15/nrpe-2.15.tar.gz
tar xzvf nrpe-2.15.tar.gz
cd nrpe-2.15
./configure
make all
make install-plugin
make install-daemon
make install-daemon-config
make install-xinetd

echo "MEMASUKAN IP NAGIOS SERVER"
vi /etc/xinetd.d/nrpe
#only_from = 127.0.0.1 localhost <masukan ip server nagios>
echo "TELAH MEMASUKAN IP NAGIOS SERVER"

echo "MEMASUKAN PORT SERVICE NRPE"
vi /etc/services
#add "nrpe            5666/tcp                 NRPE" (tambahkan baris service baru nrpe)
echo "TELAH MEMASUKAN PORT SERVICE NRPE"

echo "RESTART SERVICE XINETD"
/etc/init.d/xinetd restart

echo "MENAMBAH RULES IPTABLES"
iptables -A INPUT -p tcp -m tcp --dport 5666 -j ACCEPT
service iptables save

echo "MENGECEK NRPE VERSION"
/usr/local/nagios/libexec/check_nrpe -H localhost
echo "NRPE CHECK_USER"
/usr/local/nagios/libexec/check_nrpe -H localhost -c check_users
echo "NRPE CHECK_LOAD"
/usr/local/nagios/libexec/check_nrpe -H localhost -c check_load
echo "NRPE CHECK_TOTAL_PROCS"
/usr/local/nagios/libexec/check_nrpe -H localhost -c check_total_procs
echo "NRPE CHECK_ZOMBIE_PROCS"
/usr/local/nagios/libexec/check_nrpe -H localhost -c check_zombie_procs

#source : http://www.tecmint.com/how-to-add-linux-host-to-nagios-monitoring-server/
