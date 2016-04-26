#ifndef HASH_SALES_DATA_H
#define HASH_SALES_DATA_H

#include "Sales_data.h"

namespace std
{
	template<>
	struct hash<Sales_data>
	{
		using result_type = size_t;
		using argument_type = Sales_data;
		size_t operator()(const Sales_data &s) const;
	};
	
	size_t hash<Sales_data>::operator() (const Sales_data &s) const
	{
		return hash<string>()(s.bookNo) ^
			hash<unsigned>()(s.units_sold) ^
			hash<double>()(s.revenue);
	}
}







#endif