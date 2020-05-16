upload:
	platformio -f -c vim run --target upload --upload-port /dev/ttyUSB0

clean:
	platformio -f -c vim run --target clean

program:
	platformio -f -c vim run --target program

uploadfs:
	platformio -f -c vim run --target uploadfs

update:
	platformio -f -c vim update

compiledb:
	pio run -t compiledb
