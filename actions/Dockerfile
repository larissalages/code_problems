FROM ubuntu
MAINTAINER Larissa Lages
RUN apt-get update
RUN apt-get install -y python3
RUN apt-get install -y python3-unittest2
COPY ./ ./
RUN chmod +x actions/run_tests.sh
CMD ./actions/run_tests.sh


