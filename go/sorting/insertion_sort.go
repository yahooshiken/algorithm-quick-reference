package sorting

type InsertionSort struct {
}

func (b InsertionSort) Sort(arr []int, sortType SortType) []int {
	length := len(arr)

	for i := 0; i < length; i++ {
		j := i
		for j >= 1 && Compare(arr[j-1], arr[j], sortType) {
			arr[j-1], arr[j] = arr[j], arr[j-1]
			j--
		}
	}

	return arr
}
