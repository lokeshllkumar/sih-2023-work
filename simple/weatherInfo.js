const apiKey = "306290ad3784e6f2e94789a6f03dbad6"; //include the API key for the OpenWeatherMap weather API

async function fetchWeatherData()
{
    try
    {
        const position = await new Promise((resolve, reject) => {
            const successCB = (position) => resolve(position);
            const errorCB = (error) => reject(error);
            navigator.geolocation.getCurrentPosition(successCB, errorCB);
        });
        
        const lat = position.coords.latitude;
        const long = position.coords.longitude;

        const url = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${long}&appid=${apiKey}`;

        const weatherResponse = await fetch(url);

        if (!weatherResponse.ok)
        {
            throw new Error("Network response not okay!");
        }
        
        const data = await weatherResponse.json();

        const windSpeed = data.wind.speed;
        const rainDesc = data.weather[0].description;
        const temp = data.main.temp - 273.15; //retrieved in Kelvin, displayed in degree Celsius
        
        const weatherInfo = {
            'wind-speed': windSpeed,
            'rain-description': rainDesc,
            temperature: temp
        };
        
        return weatherInfo;
    }
    catch (err)
    {
        console.log(error);
        throw(error);
    }
}

fetchWeatherData()
    .then((weatherInfo) => {
        console.log(weatherInfo);
    })
    .catch((err) => {
        console.log("Error in fetching weather data!");
    });