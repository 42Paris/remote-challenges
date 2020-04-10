FROM haskell

RUN mkdir -p /home/chall0
WORKDIR /home/chall0
COPY lmarques.hs lmarques.hs
RUN ghc lmarques.hs
CMD ["./lmarques"]