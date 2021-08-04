package sorting

type MergeSort struct {
	workArr []int
}

func (m MergeSort) Sort(arr []int, sortType SortType) []int {
	length := len(arr)
	m.workArr = make([]int, length)
	return m.MergeSort(arr, 0, length-1, sortType)
}

func (m MergeSort) MergeSort(arr []int, low int, high int, sortType SortType) []int {
	if low >= high {
		return arr
	}

	middle := (low + high) / 2

	m.MergeSort(arr, low, middle, sortType)
	m.MergeSort(arr, middle+1, high, sortType)

	for i := low; i <= middle; i++ {
		m.workArr[i] = arr[i]
	}

	j := high
	for i := middle + 1; i <= high; i++ {
		m.workArr[i] = arr[j]
		j--
	}

	i := low
	j = high

	for k := low; k <= high; k++ {
		if Compare(m.workArr[j], m.workArr[i], sortType) {
			arr[k] = m.workArr[i]
			i++
		} else {
			arr[k] = m.workArr[j]
			j--
		}
	}

	return arr
}
