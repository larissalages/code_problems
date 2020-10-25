FROM ubuntu
MAINTAINER Larissa Lages
RUN apt-get update
RUN apt-get install -y python3
RUN apt-get install -y python3-unittest2
COPY ./ ./
CMD python3 -m unittest discover classical_algorithms/python/tests


