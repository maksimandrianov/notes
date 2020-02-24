#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class IObserver
{
 public:
  virtual ~IObserver() {}
  virtual void Update(float temp, float humidity, float pressure) = 0;
};

class ISubject
{
 public:
  virtual ~ISubject() {}
  virtual void RegisterObserver(shared_ptr<IObserver> o) = 0;
  virtual void RemoveObserver(shared_ptr<IObserver> o) = 0;
  virtual void NotifyObservers() = 0;
};

class IDisplayElement
{
 public:
  virtual ~IDisplayElement() {}
  virtual void Display() = 0;
};

class WeatherData : public ISubject
{
 public:
  void RegisterObserver(shared_ptr<IObserver> o) override
  {
    _observers.emplace_back(o);
  }

  void RemoveObserver(shared_ptr<IObserver> o) override
  {
    auto el = remove(begin(_observers), end(_observers), o);
    _observers.erase(el);
  }

  void NotifyObservers() override
  {
    for (auto &o : _observers) o->Update(_temperature, _humidity, _pressure);
  }

  void MeasureChanged() { NotifyObservers(); }
  void Measurements(float t, float h, float p)
  {
    _temperature = t;
    _humidity = h;
    _pressure = p;
    MeasureChanged();
  }

 private:
  vector<shared_ptr<IObserver>> _observers;
  float _temperature;
  float _humidity;
  float _pressure;
};

class CurrentConditionsDisplay : public IObserver, public IDisplayElement
{
 public:
  void Update(float temp, float humidity, float pressure) override
  {
    (void)pressure;
    _temperature = temp;
    _humidity = humidity;
    Display();
  }

  void Display() override
  {
    cout << "CurrentConditionsDisplay"
         << " " << _temperature << " " << _humidity << endl;
  }

 private:
  float _temperature;
  float _humidity;
};

int main()
{
  auto weatherData = make_shared<WeatherData>();
  auto currCondDisplay = make_shared<CurrentConditionsDisplay>();

  weatherData->RegisterObserver(currCondDisplay);
  weatherData->Measurements(80, 65, 30.5);

  weatherData->RemoveObserver(currCondDisplay);
  weatherData->Measurements(81, 67, 30.3);

  return 0;
}
