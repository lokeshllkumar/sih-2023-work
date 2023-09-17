# sih-weather-info-retriever
Provides tools to retrieve weather information of a location via Wi-Fi/cellular connection

## Description
The tools provided make use of **HTML's Geolocation API** and the **OpenWeatherMap's Weather API** to locate a device and fetch local weather information.
### simple - 
This tool creates a test browser environment using an HTML file **index.html** and makes use of the location services provided by the web browser
After enabling permissions to access location, a function called **fetchWeatherData()** in the JavaScript file **weatherInfo.js** makes an API call to the Geolocation API to retrieve the approximate coordinates of the device's location using getCurrentPosition().
Then, an API call is made to the Weather API using the longitude and latitude fetched before, to retrieve current weather conditions as a JSON object containing keys such as average temperature, minimum temperature, maximum-temperature, wind speed, rain nature, etc.
A small subset of this data is consolidated into a new JSON object and returned from the function.

## Getting started
### simple
Using the tool requires a web browser with JavaScript enabled. Simply open **index.html** in the web browser and allow location services. The backend script contains a function called **fetchWeatherData()** performs a few API calls and finally returns a JSON object containing weather data including the average temperature, wind speed and a brief rain forecast.
