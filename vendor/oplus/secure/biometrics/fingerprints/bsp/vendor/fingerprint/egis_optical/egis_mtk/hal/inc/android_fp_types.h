/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// package android.hardware.biometrics.fingerprint@2.1;

/**
 * Request status indicates whether the request is accepted by the vendor
 * implementation or not. These values are taken from the errno set,
 * except for the SYS_UNKNOWN
 */
enum RequestStatus {
	SYS_UNKNOWN = 1,
	SYS_OK = 0,
	SYS_ENOENT = -2,
	SYS_EINTR = -4,
	SYS_EIO = -5,
	SYS_EAGAIN = -11,
	SYS_ENOMEM = -12,
	SYS_EACCES = -13,
	SYS_EFAULT = -14,
	SYS_EBUSY = -16,
	SYS_EINVAL = -22,
	SYS_ENOSPC = -28,
	SYS_ETIMEDOUT = -110,
};

/**
 * Fingerprint errors are meant to tell the framework to terminate the current
 * operation and ask for the user to correct the situation. These will almost
 * always result in messaging and user interaction to correct the problem.
 *
 * For example, ERROR_CANCELED should follow any acquisition message that
 * results in a situation where the current operation can't continue without
 * user interaction. For example, if the sensor is dirty during enrollment and
 * no further enrollment progress can be made, send ACQUIRED_IMAGER_DIRTY
 * followed by ERROR_CANCELED.
 */
enum FingerprintError {
	/** Used for testing, no error returned */
	ERROR_NO_ERROR = 0,
	/** The hardware has an error that can't be resolved. */
	ERROR_HW_UNAVAILABLE = 1,
	/** Bad data; operation can't continue */
	ERROR_UNABLE_TO_PROCESS = 2,
	/** The operation has timed out waiting for user input. */
	ERROR_TIMEOUT = 3,
	/** No space available to store a template */
	ERROR_NO_SPACE = 4,
	/** The current operation has been canceled */
	ERROR_CANCELED = 5,
	/** Unable to remove a template */
	ERROR_UNABLE_TO_REMOVE = 6,
	/** The hardware is in lockout due to too many attempts */
	ERROR_LOCKOUT = 7,
	/** Vendor-specific error message */
	ERROR_VENDOR = 8
};

/**
 * Fingerprint acquisition info is meant as feedback for the current operation.
 * Anything but ACQUIRED_GOOD must be shown to the user as feedback on how to
 * take action on the current operation. For example, ACQUIRED_IMAGER_DIRTY may
 * be used to tell the user to clean the sensor if it is detected to be dirty.
 * If this causes the current operation to fail, an additional ERROR_CANCELED
 * must be sent to stop the operation in progress (e.g. enrollment).
 * In general, these messages will result in a "Try again" message.
 */
enum FingerprintAcquiredInfo {
	ACQUIRED_GOOD = 0,
	/** sensor needs more data, i.e. longer swipe. */
	ACQUIRED_PARTIAL = 1,
	/**
	 * image doesn't contain enough detail for recognition*/
	ACQUIRED_INSUFFICIENT = 2,
	/** sensor needs to be cleaned */
	ACQUIRED_IMAGER_DIRTY = 3,
	/** mostly swipe-type sensors; not enough data collected */
	ACQUIRED_TOO_SLOW = 4,
	/** vendor-specific acquisition messages start here */
	ACQUIRED_TOO_FAST = 5,
	/** vendor-specific acquisition messages */
	ACQUIRED_VENDOR = 6
};

struct FingerprintFingerId {
	/** Group ID */
	uint32_t gid;
	/** Fingerprint template ID */
	uint32_t fid;
};
