FROM alpine:3.20 AS build

RUN apk add --no-cache cmake g++

WORKDIR /app

COPY . .

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
RUN cmake --build build

FROM alpine:3.20 AS runner
WORKDIR /app
COPY --from=build app/build/opeolluwa ./opeolluwa
COPY --from=build app/assets ./assets
COPY --from=build app/data ./data
COPY --from=build app/templates ./templates

CMD [ "./opeolluwa" ]
