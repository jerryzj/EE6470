#pragma once
#include <string>

class ShapeTy {
public:
	uint n;
	uint c;
	uint h;
	uint w;

	ShapeTy(uint n_, uint c_, uint h_, uint w_);
	ShapeTy();
	ShapeTy(int64_t* ptr, int num);
	~ShapeTy() {}

	// Default: the python-array-like presentation
	// Example: prefix seperator n seperator c seperator h seperator w suffix
	std::string to_str(
		const std::string seperator=",",
		const bool ShowIndex=false,
		const std::string prefix="[",
		const std::string suffix="]") const;
	uint size() const;
	bool operator==(const ShapeTy& rhs) const;
	void put(int64_t* ptr, int num);
	ShapeTy to_strides(int dim) const;
	inline ShapeTy to_strides() const {return this->to_strides(4);};
	uint Idx(uint ni, uint ci, uint hi, uint wi,
		const ShapeTy* strides=nullptr) const;
	inline uint Idx(uint ci, uint hi, uint wi,
			const ShapeTy* strides=nullptr) const {
		return this->Idx(0, ci, hi, wi, strides);
	};
};
