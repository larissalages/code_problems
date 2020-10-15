FROM ubuntu
MAINTAINER Larissa Lages
RUN apt-get update
RUN apt-get install -y python
RUN apt-get install -y python-unittest2
ADD classical_algorithms/python/tests/ /home/classical_algorithms/python/tests
CMD ["python -m unittest discover home/classical_algorithms/python/tests"]

