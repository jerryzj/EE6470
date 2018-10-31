#include <sstream>
#include <array>
#include <cassert>
#include "ShapeTy.h"
ShapeTy::ShapeTy(uint n_, uint c_, uint h_, uint w_)
	: n(n_), c(c_), h(h_), w(w_)
{}

ShapeTy::ShapeTy()
	: n(1), c(1), h(1), w(1)
{}

ShapeTy::ShapeTy(int64_t* ptr, int num)
	: n(1), c(1)
{
	put(ptr, num);
}

std::string ShapeTy::to_str(const std::string seperator, const bool ShowIndex,
		const std::string prefix, const std::string suffix) const {
	std::stringstream ss;
	using ArrayT = std::array<const std::string, 4>;
	const ArrayT Index1 = {"Number: ", "Channel: ", "Height: ", "Width: "};
	const ArrayT IndexNull = {"", "", "", ""};
	ArrayT Index = ShowIndex ? Index1 : IndexNull;
	ss << prefix << Index[0] << n;
	ss << seperator << Index[1] << c;
	ss << seperator << Index[2] << h;
	ss << seperator << Index[3] << w << suffix;
	return ss.str();
}

uint ShapeTy::size() const {
	assert(n>=1);
	assert(c>=1);
	assert(h>=1);
	assert(w>=1);
	return n*c*h*w;
}

void ShapeTy::put(int64_t* ptr, int num) {
	if (num == 2) {
		h = ptr[0];
		w = ptr[1];
	} else if (num == 3) {
		c = ptr[0];
		put(ptr+1, num-1);
	} else if (num == 4) {
		n = ptr[0];
		put(ptr+1, num-1);
	} else {
		assert(0);
	}
}

ShapeTy ShapeTy::to_strides(int dim) const {
	uint stride_w = 1;
	uint stride_h = 1;
	uint stride_c = 1;
	uint stride_n = 1;

	if (dim>=4) { stride_n = c * h * w; }
	if (dim>=3) { stride_c = h * w; }
	if (dim>=2) { stride_h = w; }
	return ShapeTy(stride_n, stride_c, stride_h, stride_w);
}

uint ShapeTy::Idx(uint ni, uint ci, uint hi, uint wi, const ShapeTy* strides) const {
	// If no given strides, then assume it is continue
	const auto continue_stride = this->to_strides();
	const ShapeTy stride = strides ? *strides : continue_stride;
	const auto offset = ni * stride.n
		+ ci * stride.c
		+ hi * stride.h
		+ wi * stride.w;
	return offset;
}

bool ShapeTy::operator==(const ShapeTy& rhs) const {
	const bool n_e = (this->n == rhs.n);
	const bool c_e = (this->c == rhs.c);
	const bool h_e = (this->h == rhs.h);
	const bool w_e = (this->w == rhs.w);
	return n_e & c_e & h_e & w_e;
}
