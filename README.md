# pico-temperature-tester

Compilation:
```
git clone https://github.com/alex-arce/pico-temperature-tester.git
cd pico-temperature-tester
mkdir build
cd build
export PICO_SDK_PATH=<pico-sdk location> # Just in case you haven't added it to .bashrc or similar...
cmake ..
make
```

Now you can copy the generated .uf2 file inside 'build/' to your Raspberry Pico :-D
