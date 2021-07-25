package sorting

type SelectionSort struct {
}

func (s SelectionSort) Sort(arr []int, sortType SortType) []int {
	length := len(arr)

	for i := 0; i < length; i++ {
		minIndex := i
		for j := i + 1; j < length; j++ {
			if Compare(arr[minIndex], arr[j], sortType) {
				minIndex = j
			}
		}
		arr[i], arr[minIndex] = arr[minIndex], arr[i]
	}

	return arr
}
