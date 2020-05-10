part of loglib;

class Logger {
  var _isEnabled;

  set isEnabled(var value) => _isEnabled = value;
  get isEnabled => _isEnabled;

  log(msg) => print("LOG: $msg");
}
