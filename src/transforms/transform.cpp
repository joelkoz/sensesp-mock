#include "transform.h"


// Transform

std::set<TransformBase*> TransformBase::transforms;

TransformBase::TransformBase(String sk_path, String id, String schema) :
    Configurable{id, schema}, SignalKSource(sk_path), WantsEnable(5) {
  transforms.insert(this);
}
