FROM ubuntu:18.04

# Установка зависимостей
RUN apt-get update && \
    apt-get install -yy gcc g++ cmake

# Копирование исходников
COPY . /print/
WORKDIR /print

# Сборка проекта
RUN cmake -H. -B_build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build _build

# Создание структуры для установки (с правильными путями)
RUN mkdir -p _install/bin && \
    cp _build/hello_world_application/hello_world_app _install/bin/ && \
    cp _build/solver_application/solver_app _install/bin/

# Настройка переменных окружения
ENV LOG_PATH /home/logs/log.txt
VOLUME /home/logs

WORKDIR /print/_install/bin

# Создаем скрипт-обертку
RUN echo '#!/bin/sh\nif [ "$1" = "solver" ]; then\n  exec ./solver_app\nelse\n  exec ./hello_world_app\nfi' > entrypoint.sh && \
    chmod +x entrypoint.sh

ENTRYPOINT ["./entrypoint.sh"]
