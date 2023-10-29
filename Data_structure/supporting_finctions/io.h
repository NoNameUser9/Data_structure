#pragma once
#include <string>
#include "struct.h"

void write_vec(node_time* vec, Table& table, const std::string& path);
void read_vec(Table& a, const std::string& path);
