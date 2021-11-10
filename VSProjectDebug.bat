@set folder=build-vseditor
@if exist %folder% (
	@echo Exist directory:%folder%,clear...
	@rmdir /S /Q %folder%
	@mkdir %folder%
) else (
	@echo Create directory:%folder%
	@mkdir %folder%
) 
@cd %folder%
::@cmake  .. -G"Visual Studio 16 2019" -Ax64
@cmake  .. 
PAUSE