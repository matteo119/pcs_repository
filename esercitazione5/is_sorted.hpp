template<typename T>
bool is_sorted(const std::vector<T>& vec) {
	if (vec.size() == 0) {
		return 1;
	}
	
	for (int i=0; i < vec.size()-1; i++) {
		if (vec[i] > vec[i+1]) {
			return 0;
		}
	}
	return 1;
}