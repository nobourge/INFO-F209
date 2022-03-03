//
// Created by Anton Romanova on 15/02/2022.
//

#include "v1_api.h" // v1:


template<class... Middlewares>
unsigned int V1Api<Middlewares...>::GetVersion() const {
  return version_;
}
