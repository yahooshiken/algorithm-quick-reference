package sorting

type QuickSort struct{}

func (q QuickSort) Sort(arr []int, sortType SortType) []int {
	length := len(arr)
	return q.QuickSort(arr, 0, length-1)
}

func (q QuickSort) QuickSort(arr []int, low int, high int) []int {
	if low < high {
		pivot := q.Partition(arr, low, high)
		q.QuickSort(arr, low, pivot-1)
		q.QuickSort(arr, pivot+1, high)
	}
	return arr
}

func (q QuickSort) Partition(arr []int, low int, high int) int {
	pivot := arr[high]

	i := low - 1
	j := high

	for true {
		i++
		for arr[i] < pivot {
			i++
		}

		j--
		for i < j && arr[j] > pivot {
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
