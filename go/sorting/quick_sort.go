package sorting

type QuickSort struct{}

func (q QuickSort) Sort(arr []int, sortType SortType) []int {
	length := len(arr)
	return q.QuickSort(arr, 0, length-1, sortType)
}

func (q QuickSort) QuickSort(arr []int, low int, high int, sortType SortType) []int {
	if low < high {
		pivot := q.Partition(arr, low, high, sortType)
		q.QuickSort(arr, low, pivot-1, sortType)
		q.QuickSort(arr, pivot+1, high, sortType)
	}
	return arr
}

func (q QuickSort) Partition(arr []int, low int, high int, sortType SortType) int {
	pivot := arr[high]

	i := low - 1
	j := high

	for true {
		i++

		for Compare(pivot, arr[i], sortType) {
			i++
		}

		j--

		for i < j && Compare(arr[j], pivot, sortType) {
			j--
		}

		if j <= i {
			break
		}

		arr[i], arr[j] = arr[j], arr[i]
	}

	arr[i], arr[high] = arr[high], arr[i]

	return i
}
