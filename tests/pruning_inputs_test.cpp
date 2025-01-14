//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   P R U N I N G   I N P U T S   T E S T   C L A S S   H E A D E R       
//
//   Artificial Intelligence Techniques SL
//   artelnics@artelnics.com                                           

#include "pruning_inputs_test.h"


PruningInputsTest::PruningInputsTest() : UnitTesting()
{
    training_strategy.set(&neural_network, &data_set);
    pruning_inputs.set(&training_strategy);

    training_strategy.set_display(false);
    pruning_inputs.set_display(false);
}


PruningInputsTest::~PruningInputsTest()
{
}


void PruningInputsTest::test_constructor()
{
    cout << "test_constructor\n";

    // Test

    PruningInputs pruning_inputs_1(&training_strategy);

    assert_true(pruning_inputs_1.has_training_strategy(), LOG);

    // Test

    PruningInputs pruning_inputs_2;

    assert_true(!pruning_inputs_2.has_training_strategy(), LOG);
}


void PruningInputsTest::test_destructor()
{
    cout << "test_destructor\n";

    PruningInputs* pruning_inputs_pointer = new PruningInputs;

    delete pruning_inputs_pointer;
}


void PruningInputsTest::test_perform_inputs_selection()
{
    cout << "test_perform_inputs_selection\n";

    InputsSelectionResults inputs_selection_results;

    // Test

    data_set.generate_Rosenbrock_data(40,3);
    data_set.split_samples_random();

    neural_network.set(NeuralNetwork::ProjectType::Approximation, {2,6,1});

    TrainingStrategy training_strategy(&neural_network, &data_set);
    pruning_inputs.set(&training_strategy);
    inputs_selection_results = pruning_inputs.perform_inputs_selection();

    assert_true(inputs_selection_results.optimal_input_columns_indices[0] == 0, LOG);

    // Test

    data_set.generate_sum_data(40,2);

    neural_network.set(NeuralNetwork::ProjectType::Approximation, {2,6,1});

    training_strategy.set(&neural_network, &data_set);
    pruning_inputs.set(&training_strategy);
    inputs_selection_results = pruning_inputs.perform_inputs_selection();

    assert_true(inputs_selection_results.optimal_input_columns_indices(0) == 0, LOG);
}


void PruningInputsTest::run_test_case()
{
    cout << "Running pruning input test case...\n";

    // Constructor and destructor methods

    test_constructor();
    test_destructor();

    // Input selection methods

    test_perform_inputs_selection();

    cout << "End of pruning input test case.\n\n";

}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2021 Artificial Intelligence Techniques, SL.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
