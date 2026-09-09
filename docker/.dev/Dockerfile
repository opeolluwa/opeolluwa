FROM alpine:3.14 AS build

RUN apk add --no-cache cmake g++
RUN apk update && apk upgrade --no-cache

WORKDIR /app 

COPY . .

RUN cmake -S . -B build 

RUN cmake --build build 

FROM alpine:3.14  AS runner 
WORKDIR /app
COPY --from=build app/build/opeolluwa ./opeolluwa
COPY --from=build app/assets ./assets
COPY --from=build app/public ./public
COPY --from=build app/data ./data
COPY --from=build app/templates ./templates

CMD [ "./opeolluwa" ]