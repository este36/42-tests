FROM ubuntu:latest

WORKDIR /root

RUN apt-get update && apt-get install -y \
build-essential clang git curl libbsd-dev valgrind \
python3 python3-pip python3-venv python3-venv python3-dev python3-setuptools pipx

ENV CC=clang
ENV PATH=/root/.local/bin:$PATH

RUN pipx install norminette &&  pipx ensurepath

RUN python3 -m venv /root/venv
RUN chmod +x /root/venv/bin/activate

RUN /root/venv/bin/pip install --upgrade pip
RUN git clone https://github.com/thecloudrazor/francinette.git

# RUN /root/venv/bin/pip install -r /root/francinette/requirements.txt

RUN bash -c "$(curl -fsSL https://raw.githubusercontent.com/thecloudrazor/francinette/master/bin/install.sh)"

WORKDIR /mnt
VOLUME /mnt

CMD ["/root/francinette/tester.sh"]
