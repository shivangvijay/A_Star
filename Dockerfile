FROM alpine:3.17.0 AS build

RUN apk update && \
    apk add --no-cache \
    build-base \
    cmake \
    tree

COPY . /app

WORKDIR /app/build

RUN cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build . --parallel 8

RUN tree 

##########################################################

FROM alpine:3.17.0

RUN apk update && \
    apk add --no-cache \
    libstdc++ 

RUN addgroup -S shs && adduser -S shs -G shs
USER shs

COPY --chown=shs:shs --from=build \
    /app/build/Explore \
    ./app/

ENTRYPOINT [ "/app/Explore" ]