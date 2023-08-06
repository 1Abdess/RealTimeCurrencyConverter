# Real Time Currency Converter in C++
*created by Abdessamad G.*

This project has been developed with the primary aim of providing pure entertainment.
Its objective is to facilitate the acquisition of knowledge regarding communication protocols between a server and a local machine through the utilization of the C++ programming language.

The designated API endpoint for this endeavor is located at [currency API](http://currencyapi.com "currency API").
This API endpoint affords us the capability to effectuate HTTP GET requests, thereby enabling the retrieval of JSON-formatted data.
To facilitate the parsing and manipulation of the acquired data, we shall harness the capabilities of the [Lohmann - "JSON for Modern C++"](https://github.com/nlohmann/json) library.

To install all the necessary components, simply execute the "installDependency.sh" file, which will orchestrate the automatic setup of the entire project.
In the terminal input the following command:
```bash
./installDependency.sh
```

To compile the project, navigate to the "src/" directory and execute the following command in the terminal:
```bash
g++ main.cpp -o currencyConverter -lcurl
```
However, before proceeding with the compilation process, kindly ensure that you have created an API key on the specified website and subsequently updated the code with your personalized API key.


Once the project has been successfully compiled, if you require insight into its functionality and the currencies it can convert, simply input the following command in the terminal:
```bash
./currencyConverter --help
```
