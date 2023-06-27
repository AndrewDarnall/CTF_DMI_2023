FROM ubuntu:latest
COPY auth.c /home
COPY flag.txt /home
COPY credentials.txt /home
COPY challenge_setup.sh /home
RUN apt-get update -y && apt-get install -y telnetd && apt-get install -y inetutils-inetd && apt-get install -y iproute2 && useradd -m admin && echo "admin:admin" | chpasswd && adduser admin sudo && apt-get install -y gcc && bash /home/challenge_setup.sh
CMD ["inetutils-inetd","-d"]