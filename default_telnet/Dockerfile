FROM ubuntu:latest
RUN apt-get update -y && apt-get install -y telnetd && apt-get install -y inetutils-inetd && apt-get install -y iproute2 && useradd -m admin && echo "admin:admin" | chpasswd && adduser admin sudo
COPY flag.txt /home
CMD ["inetutils-inetd","-d"]
# Beware, if one command/layer fails while building, the whole image gets fucked up