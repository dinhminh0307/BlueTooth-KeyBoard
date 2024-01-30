import asyncio
from bleak import BleakClient

address = "ESP32_BLE_ADDRESS"  # Replace with your ESP32 BLE Address
characteristic_uuid = "beb5483e-36e1-4688-b7f5-ea07361b26a8"

def notification_handler(sender, data):
    """Simple notification handler which prints the data received."""
    print(f"Received data: {data}")

async def run(address, loop):
    async with BleakClient(address, loop=loop) as client:
        x = await client.is_connected()
        print(f"Connected: {x}")

        await client.start_notify(characteristic_uuid, notification_handler)
        await asyncio.sleep(30)  # Keep the connection for 30 seconds
        await client.stop_notify(characteristic_uuid)

loop = asyncio.get_event_loop()
loop
