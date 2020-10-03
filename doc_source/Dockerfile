FROM miktex/miktex:2.9.6990

RUN apt-get -y install dos2unix
RUN mpm --update-db

ADD compile.sh /usr/local/bin/compile.sh
RUN chmod 777 /usr/local/bin/compile.sh
RUN dos2unix /usr/local/bin/compile.sh

ENTRYPOINT ["/usr/local/bin/compile.sh"]
# ENTRYPOINT [""]