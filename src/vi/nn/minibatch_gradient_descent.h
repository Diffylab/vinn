#ifndef __vinn__minibatch_gradient_descent__
#define __vinn__minibatch_gradient_descent__

#include <vi/nn/trainer.h>
#include <vi/nn/network.h>

namespace vi {
namespace nn {

class minibatch_gradient_descent : public trainer {
public:
  minibatch_gradient_descent(const size_t max_epoch_count,
                             const double learning_rate,
                             const size_t batch_size,
                             const size_t batch_iteration_count = 1);

  virtual double train(vi::nn::network& network, const vi::la::matrix& features,
                       const vi::la::matrix& targets,
                       vi::nn::cost_function& cost_function);

private:
  double _learning_rate;
  size_t _max_epoch_count;
  size_t _batch_size;
  size_t _batch_iteration_count;
};

}
}

#endif

