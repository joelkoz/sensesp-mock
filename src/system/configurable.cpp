
#include "configurable.h"

#define debugW printf
#define debugI printf


// Define a global configurable map. Rationale for a global variable:
// Every Configurable with an id gets registered, and carrying an object
// reference around would unnecessarily reduce readability of the code.
std::map<String, Configurable*> configurables;

Configurable::Configurable(String id, String schema)
    : id{id}, schema{schema} {
  if (id != "") {
    auto it = configurables.find(id);
    if (it != configurables.end()) {
      debugW("WARNING: Overriding id %s", id.c_str());
    }
    configurables[id] = this;
  }
}

// Returns the current configuration
JsonObject& Configurable::get_configuration(JsonBuffer& buf) {
  debugW("WARNING: get_configuration not defined");
  return buf.createObject();
}

// Sets and saves the configuration
bool Configurable::set_configuration(const JsonObject& config) {
  debugW("WARNING: set_configuration not defined");
  return false;
}

// Returns the configuration schema.
// The schema is a Json object defining and describing the configuration
// keys and possibly allowed value types. The schema can be used
// in client code to render a configuration UI with helpful
// descriptions.
// Schema format TBD.
String Configurable::get_config_schema() {
  return "{}";
}

void Configurable::load_configuration() {
}

void Configurable::save_configuration() {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& obj = get_configuration(jsonBuffer);
}
