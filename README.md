# ESP32-74HC595-74HC165-con-OpenPLC
ESP32 + 74HC595 + 74HC165 con OpenPLC

Autor: Jaime Iglesias

## Descripción

Este proyecto utiliza una placa ESP32 WROOM para gestionar entradas y salidas digitales utilizando registros de desplazamiento:
- **74HC595** para salidas (RELE_0 a RELE_7)
- **74HC165** para entradas (INT_1 a INT_8)

Todo integrado con el entorno **OpenPLC**.

## Conexiones

### 74HC595 (salidas)
- **DS** → GPIO12
- **SH_CP** → GPIO22
- **ST_CP** → GPIO23
- **QH** → GPIO15
- **SH_CP** → GPIO2

### 74HC165 (entradas)

- **ST_CP** → GPIO0
