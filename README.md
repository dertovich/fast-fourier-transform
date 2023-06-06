# fast-fourier-transform
## Описание
Был сделан выбор в пользу 2 варианта. На это повлияло два фактора:
1. Опыт написания программы по вычислению ДПФ
2. Желание углубить знания о преобразованиях Фурье
![image](https://github.com/dertovich/fast-fourier-transform/assets/86295099/96068a25-3059-481c-bef5-fdf84a294fe0)

## Структура проекта 
- `source/` - содержит класс БПФ и main файл
- `include/` - содержит заголовочный файл
- `example/` - содержит файлы данных в json-формате
- `Makefile` - файл сборки проекта
- `Dockerfile` - фай сборки контейнера проекта

## Установка 
Склонируйте репозиторий
```
git clone https://github.com/dertovich/fast-fourier-transform.git
```

Перейдите в директорию проекта
```
cd fast-fourier-transform
```

Запустите контейнер проекта
```
doker build -t fasttransform .
```
## Запуск
Запустите сборку проекта
```
docker run fasttransform
```
![2023-06-06_18-28-11](https://github.com/dertovich/fast-fourier-transform/assets/86295099/2d7754f0-d373-4099-a24d-fbff84eff781)




## Использование


## Полезные источники
Статья на хабре о преобразовании Фурье https://habr.com/ru/articles/196374/

Доходчивое объяснение схемы Кули-Тьюки и не только https://algorithmica.org/ru/fft
