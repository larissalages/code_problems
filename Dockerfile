# pull the official base image (Background o.s for container)
FROM python:3.9.7

# image comes with gpg 2.x but we need gpg 1.x
RUN apt-get update && \
    apt-get remove -y gnupg && \
    apt-get install -y gnupg1

