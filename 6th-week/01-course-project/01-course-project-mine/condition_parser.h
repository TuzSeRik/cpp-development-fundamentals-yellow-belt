#pragma once

#include <memory>
#include <iostream>

#include "node.h"
// Copied parser of conditions from task description
using namespace std;

shared_ptr<Node> ParseCondition(istream& is);
